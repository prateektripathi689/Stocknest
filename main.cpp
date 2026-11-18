#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

class Printable {
public:
    virtual void display() const = 0;
    virtual ~Printable() {}
};

class Product : public Printable {
private:
    int id, quantity;
    string name, category;
    double price;
public:
    Product(int i, string n, string c, int q, double p)
        : id(i), quantity(q), name(n), category(c), price(p) {}
    int getId() const { return id; }
    double value() const { return quantity * price; }
    void setQuantity(int q) { if (q >= 0) quantity = q; }
    void display() const override {
        cout << left << setw(6) << id << setw(20) << name
             << setw(15) << category << setw(8) << quantity
             << fixed << setprecision(2) << price << endl;
    }
    void save(ofstream &f) const {
        f << id << "|" << name << "|" << category << "|" << quantity << "|" << price << endl;
    }
};

class StockNest {
    vector<Product> products;
    int nextId = 301;
    int indexOf(int id) const {
        for (int i=0;i<(int)products.size();i++)
            if(products[i].getId()==id) return i;
        return -1;
    }
public:
    void add() {
        string n,c; int q; double p;
        cin.ignore(numeric_limits<streamsize>::max(),'\\n');
        cout<<"Product name: "; getline(cin,n);
        cout<<"Category: "; getline(cin,c);
        cout<<"Quantity: "; cin>>q;
        cout<<"Price: "; cin>>p;
        if(q<0||p<0){cout<<"Invalid quantity or price.\\n";return;}
        products.emplace_back(nextId++,n,c,q,p);
        cout<<"Product added.\\n";
    }
    void showAll() const {
        if(products.empty()){cout<<"No products available.\\n";return;}
        cout<<left<<setw(6)<<"ID"<<setw(20)<<"NAME"<<setw(15)<<"CATEGORY"<<setw(8)<<"QTY"<<"PRICE\\n";
        for(const auto &p:products)p.display();
    }
    void update() {
        int id,q;cout<<"Product ID: ";cin>>id;
        int i=indexOf(id);if(i<0){cout<<"Not found.\\n";return;}
        cout<<"New quantity: ";cin>>q;
        if(q<0){cout<<"Invalid quantity.\\n";return;}
        products[i].setQuantity(q);cout<<"Stock updated.\\n";
    }
    void remove() {
        int id;cout<<"Product ID: ";cin>>id;int i=indexOf(id);
        if(i<0){cout<<"Not found.\\n";return;}
        products.erase(products.begin()+i);cout<<"Product removed.\\n";
    }
    void search() const {
        int id;cout<<"Product ID: ";cin>>id;int i=indexOf(id);
        if(i<0)cout<<"Not found.\\n";else products[i].display();
    }
    void totalValue() const {
        double total=0;for(const auto &p:products)total+=p.value();
        cout<<"Total stock value: Rs. "<<fixed<<setprecision(2)<<total<<endl;
    }
    void save() const {
        ofstream f("stocknest-records.txt");
        for(const auto &p:products)p.save(f);
        cout<<"Records saved.\\n";
    }
};

int main() {
    StockNest app; int choice;
    do {
        cout<<"\\n===== STOCKNEST =====\\n1. Add product\\n2. View products\\n3. Update stock\\n4. Delete product\\n5. Search product\\n6. Total stock value\\n7. Save records\\n0. Exit\\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1:app.add();break;
            case 2:app.showAll();break;
            case 3:app.update();break;
            case 4:app.remove();break;
            case 5:app.search();break;
            case 6:app.totalValue();break;
            case 7:app.save();break;
            case 0:app.save();cout<<"Goodbye!\\n";break;
            default:cout<<"Invalid choice.\\n";
        }
    }while(choice!=0);
    return 0;
}
