#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define TRAIN_HAM_FILE_PATH "./emails/train/dataset_ham_train100.csv"
#define TRAIN_SPAM_FILE_PATH "./emails/train/dataset_spam_train100.csv"
#define TEST_HAM_FILE_PATH "./emails/test/dataset_ham_test20.csv"
#define TEST_SPAM_FILE_PATH "./emails/test/dataset_spam_test20.csv"

#define T {0.6, 0.7, 0.8, 0.9, 0.95}

using namespace std;

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

void debugWordFrequencies(const map<string, int> m) {
  auto iter = m.begin();
  while (iter != m.end()) {
    cout << "[" << iter->first << "," << iter->second << "]\n";
    ++iter;
  }
}

int main() {
  vector<string> hamTrainDataset = loadData(TRAIN_HAM_FILE_PATH);
  map<string, int> hamTrainFrequencies = getWordFrequencies(hamTrainDataset);
  debugWordFrequencies(hamTrainFrequencies);
  // printData(hamTrainDataset);
  return 0;
}