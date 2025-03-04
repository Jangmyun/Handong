#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define TRAIN_HAM_FILE_PATH "./emails/train/dataset_ham_train100.csv"
#define TRAIN_SPAM_FILE_PATH "./emails/train/dataset_spam_train100.csv"
#define TEST_HAM_FILE_PATH "./emails/test/dataset_ham_test20.csv"
#define TEST_SPAM_FILE_PATH "./emails/test/dataset_spam_test20.csv"

#define THRESHOLD {0.6, 0.7, 0.8, 0.9, 0.95}

using namespace std;

// (num, label, text)로 이루어진 Email 구조체
struct Email {
  int num;
  string label;
  string text;
};

// split 함수
vector<string> splitText(string str, char delimiter) {
  istringstream iss(str);
  string tmp;
  vector<string> result;

  while (getline(iss, tmp, delimiter)) {
    result.push_back(tmp);
  }
  return result;
}

// text에서 특수기호 제거
string normalizeText(const string& text) {
  string normalizedText;
  for (char c : text) {
    if (isspace(c) || isalnum(c)) {
      normalizedText += toupper(c);
    }
  }
  return normalizedText;
}

bool isAllDigits(const std::string& str) {
  // 문자열이 비어 있으면 false를 반환
  if (str.empty()) return false;

  return all_of(str.begin(), str.end(), ::isdigit);
}

// 해당 row의 첫 부분 (숫자, ham or spam , 나머지 문장) 구조인지 확인
// row의 첫부분이면 숫자와 ham은 제거한 string을 리턴, 아니면 전체 string을 리턴
string checkRowStart(string s) {
  vector<string> part = splitText(s, ',');
  // size가 3보다 작으면 문자열 그대로 리턴
  if (part.size() < 3) {
    return s;
  }
  // split text 첫번째가 숫자이고, 두번째가 ham 또는 spam이면 나머지 문장 리턴
  if (isAllDigits(part[0]) && (part[1] == "ham" || part[1] == "spam")) {
    // 0,1 인덱스 문장 제외하고 하나로 합쳐서 리턴
    string catString = "";
    for (int i = 2; i < part.size(); i++) {
      catString += part[i];
      catString += " ";
    }
    return catString;
  }
  return s;
}

vector<string> loadData(const string path) {
  vector<string> emailData;
  ifstream file(path);
  if (!file.is_open()) {
    cerr << "Cannot Load Data" << '\n';
    exit(1);
  }
  string line;
  getline(file, line);
  while (getline(file, line)) {
    emailData.push_back(normalizeText(checkRowStart(line)));
  }
  return emailData;
}

void printData(vector<string> data) {
  for (string s : data) {
    cout << s << '\n';
  }
}

// 단어 빈도 구하기
map<string, int> getWordFrequencies(const vector<string>& textVec) {
  map<string, int> wordFrequencies;
  for (string text : textVec) {
    istringstream iss(text);
    string word;
    while (iss >> word) {
      wordFrequencies[word]++;
    }
  }
  return wordFrequencies;
}

int countTotalWords(map<string, int> wordFrequencies) {
  int total = 0;
  for (const pair<string, int> p : wordFrequencies) {
    total += p.second;
  }
  return total;
}

string checkEmail(string email, double spamPercentage, double hamPercentage,
                  map<string, int> spamFrequencies,
                  map<string, int> hamFrequencies, int spamTotalWords,
                  int hamTotalWords, int wordSetSize, double threshold) {
  istringstream iss(email);
  vector<string> words;
  string word;
  while (iss >> word) {
    words.push_back(word);
  }

  double logSpamPercentage = log(spamPercentage);
  double logHamPercentage = log(hamPercentage);

  for (string str : words) {
    logSpamPercentage +=
        log((spamFrequencies.count(str) ? spamFrequencies.at(str) : 0) + 1.0) -
        log(spamTotalWords + wordSetSize);
    logHamPercentage +=
        log((hamFrequencies.count(str) ? hamFrequencies.at(str) : 0) + 1.0) -
        log(hamTotalWords + wordSetSize);
  }

  double rw =
      exp(logSpamPercentage) / (exp(logSpamPercentage) + exp(logHamPercentage));
  return (rw >= threshold) ? "spam" : "ham";
}

double calculatePercentage(vector<string> testEmails, vector<string> trueLabels,
                           double spamPercentage, double hamPercentage,
                           map<string, int> spamFrequencies,
                           map<string, int> hamFrequencies, int spamTotalWords,
                           int hamTotalWords, int wordSetSize,
                           double threshold) {
  int correct = 0;
  for (int i = 0; i < testEmails.size(); i++) {
    string prediction = checkEmail(
        testEmails[i], spamPercentage, hamPercentage, spamFrequencies,
        hamFrequencies, spamTotalWords, hamTotalWords, wordSetSize, threshold);
    if (prediction == trueLabels[i]) {
      correct++;
    }
  }
  return (double)correct / testEmails.size();
}

int main() {
  // Train 데이터 읽어오기
  vector<string> hamTrainDataset = loadData(TRAIN_HAM_FILE_PATH);
  vector<string> spamTrainDataset = loadData(TRAIN_SPAM_FILE_PATH);

  // train data의 단어 빈도 수 계산
  map<string, int> hamTrainFrequencies = getWordFrequencies(hamTrainDataset);
  map<string, int> spamTrainFrequencies = getWordFrequencies(spamTrainDataset);

  // 전체 단어의 개수 세기
  int hamTotal = countTotalWords(hamTrainFrequencies);
  int spamTotal = countTotalWords(spamTrainFrequencies);

  // Test 데이터 읽어오기
  vector<string> hamTestDataset = loadData(TEST_HAM_FILE_PATH);
  vector<string> spamTestDataset = loadData(TEST_SPAM_FILE_PATH);

  // word set size 구하기
  set<string> wordSet;
  for (const pair<string, int> p : hamTrainFrequencies) {
    wordSet.insert(p.first);
  }
  for (const pair<string, int> p : spamTrainFrequencies) {
    wordSet.insert(p.first);
  }
  int setSize = wordSet.size();

  double spamPercentage = (double)spamTestDataset.size() /
                          (spamTestDataset.size() + hamTestDataset.size());
  double hamPercentage = (double)hamTestDataset.size() /
                         (spamTestDataset.size() + hamTestDataset.size());

  // spam test와 ham test가 모두 포함 된 string vector 생성
  vector<string> testEmails = hamTestDataset;
  testEmails.insert(testEmails.end(), spamTestDataset.begin(),
                    spamTestDataset.end());
  vector<string> trueLabels(hamTestDataset.size(), "ham");
  trueLabels.insert(trueLabels.end(), spamTestDataset.begin(),
                    spamTestDataset.end());

  for (double threshold : THRESHOLD) {
    double accuracy = calculatePercentage(
        testEmails, trueLabels, spamPercentage, hamPercentage,
        spamTrainFrequencies, hamTrainFrequencies, spamTotal, hamTotal, setSize,
        threshold);
    cout << "threshold:" << threshold << "/ accuracy:" << accuracy << '\n';
  }
  return 0;
}