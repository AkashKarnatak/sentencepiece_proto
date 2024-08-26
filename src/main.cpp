#include "builtin_pb/sentencepiece_model.pb.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>

int main() {
  std::cout << std::filesystem::current_path() << std::endl;
  std::fstream input("../xlnet-base-cased-spiece.model",
                     std::ios::in | std::ios::binary);

  sentencepiece::ModelProto model;

  if (!input) {
    std::cout << "File not found" << std::endl;
    return 1;
  } else if (!model.ParseFromIstream(&input)) {
    std::cerr << "Failed to parse model file" << std::endl;
  }

  std::unordered_map<std::string, float> vocab;
  for (auto x: model.pieces()) {
    vocab.emplace(x.piece(), x.score());
  }

  std::cout << model.pieces().size() << std::endl;
  for (auto x : model.pieces()) {
    std::cout << x.piece() << std::endl;
    std::cout << x.score() << std::endl;
    switch (x.type()) {
    case 1:
      std::cout << "normal" << std::endl;
      break;
    case 2:
      std::cout << "unknown" << std::endl;
      break;
    case 3:
      std::cout << "control" << std::endl;
      break;
    case 4:
      std::cout << "user_defined" << std::endl;
      break;
    case 5:
      std::cout << "unused" << std::endl;
      break;
    case 6:
      std::cout << "byte" << std::endl;
      break;
    }
    std::cout << "---------------" << std::endl;
  }

  return 0;
}
