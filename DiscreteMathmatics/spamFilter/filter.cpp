#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 특수 문자 제거 및 소문자 변환
string cleanText(const string &text) {
  string cleaned;
  for (char c : text) {
    if (isalnum(c) || isspace(c)) {
      cleaned += tolower(c);
    }
  }
  return cleaned;
}

// 단어 빈도 계산
map<string, int> calculateWordFrequencies(const vector<string> &emails) {
  map<string, int> wordFrequencies;
  for (const string &email : emails) {
    istringstream iss(cleanText(email));
    string word;
    while (iss >> word) {
      wordFrequencies[word]++;
    }
  }
  return wordFrequencies;
}

// 데이터 읽기
vector<string> loadEmails(const string &filePath) {
  vector<string> emails;
  ifstream file(filePath);
  if (!file.is_open()) {
    cerr << "Error opening file: " << filePath << endl;
    exit(1);
  }
  string line;
  while (getline(file, line)) {
    emails.push_back(line);
  }
  return emails;
}

// 확률 계산
double calculateProbability(const vector<string> &tokens,
                            const map<string, int> &wordFrequencies,
                            int totalWords, int vocabularySize) {
  double probability = 1.0;
  for (const string &word : tokens) {
    int wordCount = wordFrequencies.count(word) ? wordFrequencies.at(word) : 0;
    probability *=
        (wordCount + 1.0) / (totalWords + vocabularySize);  // 라플라스 스무딩
  }
  return probability;
}

// 이메일 분류
string classifyEmail(const string &email, double spamPrior, double hamPrior,
                     const map<string, int> &spamFrequencies,
                     const map<string, int> &hamFrequencies, int spamTotalWords,
                     int hamTotalWords, int vocabularySize, double threshold) {
  istringstream iss(cleanText(email));
  vector<string> tokens;
  string word;
  while (iss >> word) {
    tokens.push_back(word);
  }

  double spamLikelihood = log(spamPrior);
  double hamLikelihood = log(hamPrior);

  for (const string &token : tokens) {
    spamLikelihood +=
        log((spamFrequencies.count(token) ? spamFrequencies.at(token) : 0) +
            1.0) -
        log(spamTotalWords + vocabularySize);
    hamLikelihood +=
        log((hamFrequencies.count(token) ? hamFrequencies.at(token) : 0) +
            1.0) -
        log(hamTotalWords + vocabularySize);
  }

  double r = exp(spamLikelihood) / (exp(spamLikelihood) + exp(hamLikelihood));
  return (r >= threshold) ? "spam" : "ham";
}

// 정확도 계산
double calculateAccuracy(const vector<string> &testEmails,
                         const vector<string> &trueLabels, double spamPrior,
                         double hamPrior,
                         const map<string, int> &spamFrequencies,
                         const map<string, int> &hamFrequencies,
                         int spamTotalWords, int hamTotalWords,
                         int vocabularySize, double threshold) {
  int correct = 0;
  for (size_t i = 0; i < testEmails.size(); ++i) {
    string predictedLabel = classifyEmail(
        testEmails[i], spamPrior, hamPrior, spamFrequencies, hamFrequencies,
        spamTotalWords, hamTotalWords, vocabularySize, threshold);
    if (predictedLabel == trueLabels[i]) {
      correct++;
    }
  }
  return (double)correct / testEmails.size();
}

int main() {
  // 파일 경로
  string hamTrainFile = "emails/train/dataset_ham_train100.csv";
  string spamTrainFile = "emails/train/dataset_spam_train100.csv";
  string hamTestFile = "emails/test/dataset_ham_test20.csv";
  string spamTestFile = "emails/test/dataset_spam_test20.csv";

  // 데이터 읽기
  vector<string> hamTrain = loadEmails(hamTrainFile);
  vector<string> spamTrain = loadEmails(spamTrainFile);
  vector<string> hamTest = loadEmails(hamTestFile);
  vector<string> spamTest = loadEmails(spamTestFile);

  // 학습 데이터 단어 빈도 계산
  map<string, int> hamFrequencies = calculateWordFrequencies(hamTrain);
  map<string, int> spamFrequencies = calculateWordFrequencies(spamTrain);

  // 총 단어 수 계산
  int hamTotalWords = 0, spamTotalWords = 0;
  for (const auto &pair : hamFrequencies) hamTotalWords += pair.second;
  for (const auto &pair : spamFrequencies) spamTotalWords += pair.second;

  // 사전 크기 계산
  set<string> vocabulary;
  for (const auto &pair : hamFrequencies) vocabulary.insert(pair.first);
  for (const auto &pair : spamFrequencies) vocabulary.insert(pair.first);
  int vocabularySize = vocabulary.size();

  // 사전 확률 계산
  double spamPrior =
      (double)spamTrain.size() / (spamTrain.size() + hamTrain.size());
  double hamPrior =
      (double)hamTrain.size() / (spamTrain.size() + hamTrain.size());

  // 테스트 데이터 라벨
  vector<string> testEmails = hamTest;
  testEmails.insert(testEmails.end(), spamTest.begin(), spamTest.end());

  vector<string> trueLabels(hamTest.size(), "ham");
  trueLabels.insert(trueLabels.end(), spamTest.size(), "spam");

  // Threshold별 정확도 계산
  vector<double> thresholds = {0.6, 0.7, 0.8, 0.9, 0.95};
  for (double threshold : thresholds) {
    double accuracy =
        calculateAccuracy(testEmails, trueLabels, spamPrior, hamPrior,
                          spamFrequencies, hamFrequencies, spamTotalWords,
                          hamTotalWords, vocabularySize, threshold);
    cout << "Threshold: " << threshold << " | Accuracy: " << accuracy << endl;
  }

  return 0;
}
