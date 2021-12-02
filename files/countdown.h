#ifndef countdown_h
#define countdown_h
#include <iostream>
#include <cctype>
#include <vector>
#include <random>
#include <filesystem>

class Countdown {
  private:
    int target = 0, big = 2, little = 4, solve;
    // std::string path = std::filesystem::current_path();
    // std::string toReplace("files");
    // std::size_t pos = path.find(toReplace);
    // std::path.replace(pos, toReplace.length(), "games");

    // Range for Target value
    std::vector<int> target_range {100, 1001},
    big_values_limits {20, 100},
    little_values_limits {1, 10},
    values;

    std::vector<std::string> file,
    errors;

    // Continue or End
    char option;

    // String clear
    std::string clear = "\033[H\033[2J\033[3J";

    // Filename variable
    std::string filename;

    void runHeader();
    void regenerateHeader(char);
    void runGame(bool);
    void runPrintToFile();
    void runOptions(char);
    void runMenu();
    void runAbout();
    void resetDefaults();
    void runEnd();
    char buildFile(std::string, std::string);
    int returnBig();
    int returnLittle();
    int numberGenerator(int, int);

  public:
    Countdown(){
      runHeader();
      runGame(false);
      runAbout();
      runMenu();
    };

    // Countdown(int t, int s, int b, int l){};
    ~Countdown() {
      runEnd();
      std::cout << clear;
    }


    // Mutators
    void setTargetNumber() {
      target = numberGenerator(target_range[0], target_range[1]);
    }

    void setBig() {
      int b = 0;
      while(b <= 1) {
        std::cout << "# of Large values to generate (Currently: " << big << "): ";
        std::cin >> b;
      }
      big = b;
      char head = 'l';
      regenerateHeader(head);
    }

    void setLittle() {
      int l = 0;
      while(l <= 1) {
        std::cout << "# of Small values to generate: (Currently: " << little << "): ";
        std::cin >> l;
      }
      little = l;
      char head = 's';
      regenerateHeader(head);
    }
};

#endif
