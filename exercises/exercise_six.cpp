#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

struct HuffNode {
  char character;
  int frequency;
};

void parse_sentence_to_nodes(std::string r_sentence,
                             std::priority_queue<HuffNode> &r_queue) {
  std::unordered_map<char, int> unique_characters;

  for (auto letter : r_sentence) {
    if (unique_characters.contains(letter)) {
      unique_characters.at(letter) += 1;
    } else {
      unique_characters.emplace(std::make_pair(letter, 1));
    }
  }

  for (auto [chars, freq] : unique_characters) {
    HuffNode hNode{.character = chars, .frequency = freq};
    r_queue.emplace(hNode);
  }
}

int main() {
  // shit doesnt work anymore, I have given Up!
  std::priority_queue<HuffNode> queue_p;

  std::string quickBrown = "The quick brown fox jumps over the lazy dog";

  parse_sentence_to_nodes(quickBrown, queue_p);

  for (int iter = 0; iter < queue_p.size(); ++iter)
    std::cout << queue_p.top().character;  // how do i print from this queue man

  return 0;
}