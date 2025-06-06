#include "vdovkin_LR1-2_ClassProduct.cpp"
#include "vdovkin_def.hpp"

struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  map<int, MenuItem> menu = {
      {1, {"Load products from file", []() { loadFromFile(FNAME); }}},
      {2, {"Show all products", showAllProducts}},
      {3, {"Add new product", addProduct}},
      {4,
       {"Show products by name",
        []() {
          string name;
          Enter(cin, name, "Enter product name: ")();
          showProductsByName(name);
        }}},
      {5,
       {"Show products by name and price",
        []() {
          string name;
          double price;
          Enter(cin, name, "Enter product name: ")();
          Enter(cin, price, "Enter maximum price: ")();
          showProductsByNameAndPrice(name, price);
        }}},
      {6,
       {"Show products with shelf life greater than",
        []() {
          int shelfLife;
          Enter(cin, shelfLife, "Enter minimum shelf life (days): ")();
          showProductsByShelfLife(shelfLife);
        }}},
  };

  int choice = 0;
  while (true) {

    // Вывод меню
    cout << "Menu:" << endl;
    for (const auto &item : menu) {
      cout << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Exit" << endl;

    Enter(cin, choice, "Enter your choice: ")();

    if (choice == 0) {
      clearTerminal();
      cout << "© 2025 Eugene Vdovkin" << endl;
      break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end()) {
      clearTerminal();
      menu[choice].action();
    } else {
      clearTerminal();
      cout << "Invalid choice" << endl;
    }

    cout << endl << endl;
  }

  return 0;
}
