#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void die() {
  cout << "You dun goofed.\n";
  exit(0);
}

void moneyCheck(int x) {
  if (x < 2) {
    die();
  }
}

int main() {
  cout << "Please enter a filename:\n";
  string filename;
  cin >> filename;
  ifstream file(filename);
  if (!file) die();
  int n =0;
  file >> n;
  std::vector<int> briefcases(n);

  for (size_t i = 0; i < briefcases.size(); i++) {
    int tmp;
    file >> tmp;
    briefcases.at(i) = tmp;
  }
  moneyCheck(n);
  vector<bool> chosen(n);
  int catdog = 0, sum = 0, average = 0, x = 0;
  while (true) {
    cout << "Please enter a briefcase to open:\n";
    x = 0;
    cin >> x;
    if (x == -1) break;
    if (!cin || x < 0 || x > n - 1) die();
    if (chosen.at(x)) die();
    chosen.at(x) = true;

    cout << "That briefcase held " << briefcases.at(x) << " dollars\n";
    briefcases.at(x) = 0;
    catdog = 0;
    sum = 0;
    for (size_t i = 0; i < briefcases.size(); i++) {
      if (briefcases.at(i) > 0) catdog++;
      sum += briefcases.at(i);
    }
    average = sum / catdog;
    if (catdog == 1) {
      std::cout << "You won " << average << " dollars!" << '\n';
    } else if (x == -1) {
      for (size_t i = 0; i < briefcases.size(); i++) {
        if (briefcases.at(i) > 0) {
          catdog++;
        }
        sum += briefcases.at(i);
      }
      average = 0;
      average = sum / catdog;
      std::cout << "You won " << average << " dollars!" << '\n';
    }
  }
}
