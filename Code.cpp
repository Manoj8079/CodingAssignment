#include <bits/stdc++.h>
using namespace std;


class Code{

    public:
		Code(int power, int skips, int recharges){
			this->maxi=power;
			this->curr_pwr=power;
			this->skips=skips;
			this->recharges=recharges;
		}


		bool Checker(vector<int> temp){                     
			map<vector<int>, int> dp;
			return Fxn(0, 1, temp, dp);
		}
    
	private:
		int maxi;					
		int curr_pwr;		
		int skips;
		int recharges;		

		bool Fxn(int p, int previous, vector<int>& temp, map<vector<int>, int>& dp){
			if(curr_pwr<0){
				return 0;
			}

			if(p==temp.size()){
				return 1;
			}

			vector<int> power={p, curr_pwr, skips, recharges, previous};

			if(dp.find(power)!=dp.end()){
				return dp[power];
			}

			bool result=false;
			if(skips>0){
				skips--;
				result|=Fxn(p+1, 0, temp, dp);
				skips++;
			}

	
			int enemy_power=temp[p];

			if(3==p || 7==p){
				if(previous){
					enemy_power+=temp[p-1]/2;
				}

				else{
					enemy_power+=temp[p-1];
				}
			}

			
			if(curr_pwr>=enemy_power){
				curr_pwr-=enemy_power;

				result|=Fxn(p+1, 1, temp, dp);

				curr_pwr+=enemy_power;
			}

			else if(recharges>0){
				int initial_power=curr_pwr;

				curr_pwr=maxi;
				recharges--;

				result|=Fxn(p, previous, temp, dp);
				recharges++;

				curr_pwr=initial_power;
			}

			return dp[power]=result;
		}				
	
	
};

int main() {
	int maxi;
	int skips;
	int recharges;	
    vector<int> temp;

    cout << "Enter power: ";
    cin >> maxi;
    if (maxi <= 0) {
        cout << "Provide Positive Value." << endl;
        return 0;
    }

    cout << "Enter No. Of skips: ";
    cin >> skips;
    if (skips < 0) {
        cout << "Provide Positive value." << endl;
        return 0;
    }

    
    cout << "Enter No. of recharge: ";
    cin >> recharges;
    if (recharges < 0) {
        cout << "Provide Positive value." << endl;
        return 0;
    }

    
    cout << "Enter the power of enemies at each circle:" << endl;
    for (int i = 0; i < 11; i++) {
        int p;
        cin >> p;
        temp.push_back(p);
    }


    Code obj = Code(maxi, skips, recharges);

    if (obj.Checker(temp)) {
        cout << "Abhimanyu can cross." << endl;
    } 
    
    else {
        cout << "Abhimanyu cannot cross." << endl;
    }

    return 0;

}
