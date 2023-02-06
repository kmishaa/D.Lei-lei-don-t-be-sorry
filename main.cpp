#include <iostream>
#include <vector>

using namespace std;

class Order {
public:
    Order(const int& s, const int& e, const int& c) {
        Start = s;
        End = e;
        Cost = c;
    }

    int get_start() const {
        return Start;
    }

    int get_end() const {
        return End;
    }

    int get_cost() const {
        return Cost;
    }

private:
    int Start;
    int End;
    int Cost;
};

int main() {
    int N;
    cin >> N;
    vector<Order> orders;
    for (int i = 0; i < N; i++) {
        int Start, End, Cost;
        cin >> Start >> End >> Cost;
        orders.push_back(Order(Start, End, Cost));
    }

    int Q;
    cin >> Q;
    vector<int> result;
    for (int i = 0; i < Q; i++) {
        int Start, End, Type;
        cin >> Start >> End >> Type;
        if (Type == 1) {
            int sum_cost = 0;
            for (Order o : orders) {
                if (o.get_start() >= Start && o.get_start() <= End) sum_cost += o.get_cost();
            }
            result.push_back(sum_cost);

        } else if (Type == 2) {
            int sum_time = 0;
            for (Order o : orders) {
                if (o.get_end() >= Start && o.get_end() <= End) sum_time += (o.get_end() - o.get_start());
            }
            result.push_back(sum_time);
        }
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
