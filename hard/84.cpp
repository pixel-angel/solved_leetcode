class Solution {
public:

    vector<int> calc_nse(int n, vector<int> arr){

        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){

            nse[i]=i+1;

            while(nse[i]!=n && arr[nse[i]]>=arr[i]){
                nse[i]=nse[nse[i]];
            }
        }

        return nse;
    }

    vector<int> calc_pse(int n, vector<int> arr){

        vector<int> pse(n);

        for(int i=0;i<n;i++){

            pse[i]=i-1;

            while(pse[i]!=-1 && arr[pse[i]]>=arr[i]){
                pse[i]=pse[pse[i]];
            }
        }

        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();

        auto pse=calc_pse(n,heights);
        auto nse=calc_nse(n,heights);

        int area=0;

        for(int i=0;i<n;i++){

            int h=heights[i];

            int w=nse[i]-pse[i]-1;

            area=max(area,h*w);
        }

        return area;
    }
};