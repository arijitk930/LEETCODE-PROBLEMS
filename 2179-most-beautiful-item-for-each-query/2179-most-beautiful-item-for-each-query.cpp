class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    // Step 1: Sort items by price
    sort(items.begin(), items.end());
    
    // Step 2: Build the maximum beauty at each price level
    vector<pair<int, int>> max_beauty_at_price;
    int current_max_beauty = 0;
    for (auto& item : items) {
        int price = item[0], beauty = item[1];
        current_max_beauty = max(current_max_beauty, beauty);
        max_beauty_at_price.push_back({price, current_max_beauty});
    }
    
    // Step 3: Pair queries with their original indices and sort by query value
    vector<pair<int, int>> queries_with_index;
    for (int i = 0; i < queries.size(); ++i) {
        queries_with_index.push_back({queries[i], i});
    }
    sort(queries_with_index.begin(), queries_with_index.end());
    
    // Step 4: Prepare the result array
    vector<int> result(queries.size());
    int idx = 0;  // index for items in max_beauty_at_price
    
    // Step 5: Process each query
    for (auto& [query, original_index] : queries_with_index) {
        // Move the idx pointer to the highest price <= query
        while (idx < max_beauty_at_price.size() && max_beauty_at_price[idx].first <= query) {
            ++idx;
        }
        
        // If idx > 0, there exists at least one item with price <= query
        if (idx > 0) {
            result[original_index] = max_beauty_at_price[idx - 1].second;
        } else {
            result[original_index] = 0;
        }
    }
    
    return result;
}
};