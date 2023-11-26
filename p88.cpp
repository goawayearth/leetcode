class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1=0;
        int pos2=0;
        int m1 = m;
        while(pos1<m && pos2<n){
            if(nums1[pos1]<nums2[pos2]){
                pos1++;
            }
            else if(nums1[pos1]>=nums2[pos2]){
                nums1.insert(nums1.begin()+pos1,nums2[pos2]);
                pos2++;
                pos1++;
                m++;
            }
        }
        while(pos2<n){
            nums1[pos1++]=nums2[pos2++];
        }
        while(nums1.size()>m1+n){
            nums1.pop_back();
        }
    }
};