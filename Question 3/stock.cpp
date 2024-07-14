#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 
class Stock {
public:
    string name;
    float price;
    int time;

    Stock(string namee, float pricee, int timee) {
        name=namee;
        price=pricee;
        time=timee;
    } 
};
map<string,int>m;
class Market {

public:
    vector<pair<string,Stock>> stocks;
    vector<pair<string,int>> alerts;
    void create_stock(string name,float price,int time) {
        stocks.push_back(make_pair(name,Stock(name,price,time)));
        if (!m[name]){
            m[name]=0;
        }
    }
    void get_all_stocks() {
        for ( auto stock : stocks) {
            cout << "Stock " << stock.second.name << ": Price " << stock.second.price << ", Timestamp " << stock.second.time << endl;
        }
    }
    void set_alert(string name, int val) {
        alerts.push_back(make_pair(name,val));
    }

    void trigger_alerts() {
        for (auto alert:alerts) {
            string name=alert.first;
            for (auto stock :stocks){
                if (stock.first == name){
                    if (stock.second.price<=alert.second){
                        cout << "Alert! The particular stock " << name << " is going down" << endl;
                    }
                    break;
                }
            }
                    
                
            }
        }
    
    void update_stock(string name, float price, int time) {
        float x;
        int f=0;
         for (auto &i: stocks){
            if (i.second.name==name){
                if (time>i.second.time){
                    m[name]=price-i.second.price; // change in stock price in future
                    x=price/i.second.price;
                    if (x<=0.8){
                        cout << "Alert!!! The stock " << name << " is going down" << endl; //alert if stock goes down beyond 20%
                        
                    }
                    if (x>=1.7){
                        cout << "Alert!!! The stock " << name << " is going up" << endl; //alert if stock goes up beyound 70%     
                    }
                    
                }

                else{
                    m[name]=i.second.price-price; // change in stock price of the past
                }
                
                i.second.price=price;
                i.second.time=time;
                f=1;
                break;
            }
            
         }
         if (f==0){
            cout << "Stock was not found " << endl;
         }
     }
    
    void get_top_performing_stocks() {
        int x=5,y;
        vector<pair<string, int>> v; 
        for (auto& it : m) { 
            v.push_back(it); 
    } 
        sort(v.begin(), v.end(), cmp); //sorting 
        cout << "Top 5 performing stocks" << endl;
        for (auto& it :v){
            if ((x--)==0) break;
            cout << it.first << " Has a Net change of " << it.second << "$"<< endl;
        }
    }
};

int main() {
    Market market;
    market.create_stock("AAPL", 2495.8, 163704);
    market.create_stock("MSFT", 2000.0, 152758);
    market.create_stock("GOGL", 1857.7, 12847);
    market.create_stock("TSLA", 3007.5, 221532);
    market.create_stock("JPMN", 936.5, 183922);
    market.create_stock("UBR", 1350.0, 53318);
    market.create_stock("ORAC", 1555.2, 71836);
    market.create_stock("NVDA", 8875.0, 195559);
    market.create_stock("MRCD", 1486.5, 201854);
    market.create_stock("OPAI", 1899.9, 214517);

    market.update_stock("AAPL", 3630.14, 142215);
    market.update_stock("ORAC", 2230.4, 201517);   
    market.update_stock("NVDA", 90007.3, 201453);  
    market.update_stock("GOGL", 3310.74, 75451);
    market.update_stock("UBR", 945.5, 192741);
    market.update_stock("MSFT", 945.5, 172741);
    

    market.get_all_stocks();
    market.set_alert("MSFT",1000);
    market.trigger_alerts();
    market.get_top_performing_stocks();

    return 0;
}
