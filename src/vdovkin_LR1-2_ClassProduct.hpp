#ifndef VDOVKIN_LR1_2_CLASSPRODUCT_HPP
#define VDOVKIN_LR1_2_CLASSPRODUCT_HPP

#include "vdovkin_def.hpp"

class Product {
private:
  string name;
  string manufacturer;
  double price;
  int shelfLife; // in days
  int quantity;

public:
  // Default constructor
  Product() = default;

  // Destructor
  ~Product() = default;

  // Inline get methods
  string getName() const { return name; }
  string getManufacturer() const { return manufacturer; }
  double getPrice() const { return price; }
  int getShelfLife() const { return shelfLife; }
  int getQuantity() const { return quantity; }

  // Inline set methods
  void setName(const string &n) { name = n; }
  void setManufacturer(const string &m) { manufacturer = m; }
  void setPrice(double p) { price = p; }
  void setShelfLife(int s) { shelfLife = s; }
  void setQuantity(int q) { quantity = q; }

  // Method prototypes
  void show() const;
  static Product input();
  bool isName(const string &n) const;
  bool isPriceLessOrEqual(double p) const;
  bool isShelfLifeGreater(int s) const;
};

#endif // VDOVKIN_LR1_2_CLASSPRODUCT_H
