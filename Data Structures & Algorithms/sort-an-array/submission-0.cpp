class Solution {
   public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest=i;
        if(2*i+1<n&&nums[2*i+1]>nums[largest]){
            largest=2*i+1;
        }
        if(2*i+2<n&&nums[2*i+2]>nums[largest]){
            largest=2*i+2;
        }
        if(largest!=i){
        swap(nums[i],nums[largest]);
        heapify(nums,n,largest);
        }
    }
    void heapsort(vector<int>& arr) {
        int n=arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        // Step 2: Move maximum element to the end
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);

            // Heap size becomes i
            heapify(arr, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
};