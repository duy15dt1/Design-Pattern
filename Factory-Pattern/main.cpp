#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

//base class
class EProducts{
public:
    virtual void ShowName() = 0;
};

class Phone : public EProducts{
public:
    void ShowName(){
        cout << "This is a phone" << endl;
    }
};

class Tablet : public EProducts{
public:
    void ShowName(){
        cout << "This is a tablet" << endl;
    }
};

//interface
class CreateProduct{
public:
    enum TypeProduct{
        PHONE = 0,
        TABLET = 1,
    };
    EProducts* GetProduct(int type){
        if (type == PHONE) return new Phone;
        else if (type == TABLET) return new Tablet;
        return NULL;
    }
};

class ShopProduct{
private:
    vector<EProducts*> product_list;
public:
    ShopProduct(){}
    void AddProduct(EProducts* product){
        product_list.push_back(product);
    }
    vector<EProducts*> get_product() {return product_list;}
};

int main(){
    CreateProduct* p_shop = new CreateProduct();

    EProducts* phone = p_shop->GetProduct(CreateProduct::PHONE);
    EProducts* tablet = p_shop->GetProduct(CreateProduct::TABLET);

    ShopProduct shop_product;
    shop_product.AddProduct(phone);
    shop_product.AddProduct(tablet);

    vector<EProducts*> list_product = shop_product.get_product();
    for(int i=0; i<list_product.size(); i++){
        EProducts* product = list_product.at(i);
        product->ShowName();
    }
    return 0;
}