#include "vdovkin_LR1-2_ClassProduct.hpp"
#include "vdovkin_def.hpp"
#include <iostream>

inline vector<Product> DB_Product;
const string FNAME = "products.txt";

// Display product details
inline void Product::show() const {
  cout << "Name: " << name << endl;
  cout << "Manufacturer: " << manufacturer << endl;
  cout << "Price: " << price << endl;
  cout << "Shelf Life: " << shelfLife << " days" << endl;
  cout << "Quantity: " << quantity << endl;
}

// Input product data from keyboard
inline Product Product::input() {
  Product p;
  string input;

  EnterString(cin, input, "Enter name: ")();
  p.setName(input);

  EnterString(cin, input, "Enter manufacturer: ")();
  p.setManufacturer(input);

  double price;
  EnterDouble(cin, price, "Enter price: ")();
  p.setPrice(price);

  int shelfLife;
  EnterInt(cin, shelfLife, "Enter shelf life (days): ")();
  p.setShelfLife(shelfLife);

  int quantity;
  EnterInt(cin, quantity, "Enter quantity: ")();
  p.setQuantity(quantity);

  return p;
}

// Logical methods
inline bool Product::isName(const string &n) const { return name == n; }

inline bool Product::isPriceLessOrEqual(double p) const { return price <= p; }

inline bool Product::isShelfLifeGreater(int s) const { return shelfLife > s; }

// Load products from file
inline void loadFromFile(const string &filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file." << endl;
    return;
  }
  DB_Product.clear();
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    Product p;
    string token;
    getline(ss, token, ',');
    p.setName(token);
    getline(ss, token, ',');
    p.setManufacturer(token);
    getline(ss, token, ',');
    p.setPrice(stod(token));
    getline(ss, token, ',');
    p.setShelfLife(stoi(token));
    getline(ss, token, ',');
    p.setQuantity(stoi(token));
    DB_Product.push_back(p);
  }
  file.close();
  cout << "Products loaded successfully." << endl;
}

// Add a new product
inline void addProduct() {
  Product p = Product::input();
  DB_Product.push_back(p);
  cout << "Product added successfully." << endl;
}

// Show all products
inline void showAllProducts() {
  if (DB_Product.empty()) {
    cout << "No products available." << endl;
    return;
  }
  for (const auto &p : DB_Product) {
    p.show();
    cout << "------------------------" << endl;
  }
}

// Show products by name
inline void showProductsByName(const string &name) {
  bool found = false;
  for (const auto &p : DB_Product) {
    if (p.isName(name)) {
      p.show();
      cout << "------------------------" << endl;
      found = true;
    }
  }
  if (!found)
    cout << "No products found with name: " << name << endl;
}

// Show products by name and price
inline void showProductsByNameAndPrice(const string &name, double price) {
  bool found = false;
  for (const auto &p : DB_Product) {
    if (p.isName(name) && p.isPriceLessOrEqual(price)) {
      p.show();
      cout << "------------------------" << endl;
      found = true;
    }
  }
  if (!found)
    cout << "No products found matching criteria." << endl;
}

// Show products by shelf life
inline void showProductsByShelfLife(int shelfLife) {
  bool found = false;
  for (const auto &p : DB_Product) {
    if (p.isShelfLifeGreater(shelfLife)) {
      p.show();
      cout << "------------------------" << endl;
      found = true;
    }
  }
  if (!found)
    cout << "No products found with shelf life greater than " << shelfLife
         << " days." << endl;
}
