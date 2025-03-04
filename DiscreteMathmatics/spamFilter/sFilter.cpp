#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define TEST_HAM_FILE_PATH "./emails/test/dataset_ham_test20.csv"

// Email 구조체 정의
struct Email {
  int number;
  std::string label;
  std::string text;

  // 출력을 위한 연산자 오버로딩
  friend std::ostream& operator<<(std::ostream& os, const Email& email) {
    os << "Number: " << email.number << "\n"
       << "Label: " << email.label << "\n"
       << "Text: " << email.text << "\n";
    return os;
  }
};

// CSV 라인을 파싱하는 헬퍼 함수
std::vector<std::string> parseCSVLine(const std::string& line) {
  std::vector<std::string> result;
  bool inQuotes = false;
  std::string currentField;

  for (char ch : line) {
    if (ch == '"') {
      inQuotes = !inQuotes;
    } else if (ch == ',' && !inQuotes) {
      result.push_back(currentField);
      currentField.clear();
    } else {
      currentField += ch;
    }
  }
  result.push_back(currentField);

  return result;
}

// 문자열에서 따옴표 제거
std::string removeQuotes(const std::string& str) {
  std::string result = str;
  result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
  return result;
}

// CSV 파일을 읽어서 Email 벡터를 반환하는 함수
std::vector<Email> readEmailsFromCSV(const std::string& filename) {
  std::vector<Email> emails;
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filename);
  }

  std::string line;
  bool isFirstLine = true;

  // 파일에서 한 줄씩 읽기
  while (std::getline(file, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue;  // 헤더 라인 스킵
    }

    try {
      auto fields = parseCSVLine(line);
      if (fields.size() >= 3) {
        Email email;
        email.number = std::stoi(fields[0]);
        email.label = fields[1];
        email.text = removeQuotes(fields[2]);

        emails.push_back(email);
      }
    } catch (const std::exception& e) {
      std::cerr << "Error processing line: " << line << "\n";
      std::cerr << "Error message: " << e.what() << "\n";
    }
  }

  file.close();
  return emails;
}

// 이메일을 파일에 저장하는 함수
void saveEmailsToFile(const std::vector<Email>& emails,
                      const std::string& filename) {
  std::ofstream outFile(filename);

  if (!outFile.is_open()) {
    throw std::runtime_error("Could not open output file: " + filename);
  }

  for (const auto& email : emails) {
    outFile << email << "\n";
  }

  outFile.close();
}

int main() {
  try {
    // CSV 파일에서 이메일 데이터 읽기
    auto emails = readEmailsFromCSV(TEST_HAM_FILE_PATH);

    // 콘솔에 결과 출력
    std::cout << "Successfully read " << emails.size() << " emails.\n\n";

    for (const auto& email : emails) {
      std::cout << email << "\n";
    }

    // 결과를 파일에 저장 (선택사항)
    std::string outputFilename = "processed_emails.txt";
    saveEmailsToFile(emails, outputFilename);
    std::cout << "Results have been saved to " << outputFilename << "\n";

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}