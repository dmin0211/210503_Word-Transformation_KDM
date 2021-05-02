#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int target_index;
bool visit[55];

int count_non_match(string &str1, string &str2) {
  int return_count = 0;
  for (int i = 0; i < str1.size(); ++i) {
    if (str1[i] != str2[i]) return_count++;
  }
  return return_count;
}

int bfs(string &begin, string &target, vector<string> &words) {
  queue<pair<string, int>> bfs_queue;
  for (int i = 0; i < words.size(); ++i) {
    if(words[i]==target){
      visit[i]=true;
      bfs_queue.push({target, 0});
    }
  }
  while (!bfs_queue.empty()) {
    string current = bfs_queue.front().first;
    int distance = bfs_queue.front().second;
    if (count_non_match(begin, current)==1) {
      return distance + 1;
    }
    bfs_queue.pop();
    for (int i = 0; i < words.size(); ++i) {
      if (!visit[i] && count_non_match(current, words[i])==1) {
        bfs_queue.push({words[i], distance + 1});
        visit[i]=true;
      }
    }
  }
  return 0;
}

int solution(string begin, string target, vector<string> words) {
  int answer = 0;
  memset(visit, 55, false);
  answer = bfs(begin, target, words);
  return answer;
}

int main() {
  string begin = "hit";
  string target = "cog";
  vector<string> word = {"hot", "dot", "dog", "lot", "log"};
  cout << solution(begin, target, word);
}