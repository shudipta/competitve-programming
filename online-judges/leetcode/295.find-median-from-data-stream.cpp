/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
// // ================================================
// // =================== Soln. 00 ===================
// // ================================================
// class MedianFinder {
//     priority_queue<int> lowerq, upperq;
// public:
//     MedianFinder() {

//     }
    
//     void addNum(int num) {
//         lowerq.push(num);
//         upperq.push(-lowerq.top());
//         lowerq.pop();
//         if (lowerq.size() < upperq.size()) {
//             lowerq.push(-upperq.top());
//             upperq.pop();
//         }
//     }
    
//     double findMedian() {
//         if (lowerq.size() > upperq.size())
//             return lowerq.top();
//         return (lowerq.top() - upperq.top()) / 2.0;
//     }
// };
// // ================================================
// // =================== Soln. 01 ===================
// // ================================================
// class MedianFinder {
//     priority_queue<int> lowerq, upperq;
// public:
//     MedianFinder() {

//     }
    
//     void addNum(int num) {
//         if (lowerq.size() > upperq.size()) {
//             upperq.push(-num);

//             lowerq.push(-upperq.top());
//             upperq.pop();
//             upperq.push(-lowerq.top());
//             lowerq.pop();
//         }
//         else {
//             lowerq.push(num);

//             upperq.push(-lowerq.top());
//             lowerq.pop();
//             lowerq.push(-upperq.top());
//             upperq.pop();
//         }
//     }
    
//     double findMedian() {
//         if (lowerq.size() > upperq.size())
//             return lowerq.top();
//         return (lowerq.top() - upperq.top()) / 2.0;
//     }
// };
// ================================================
// =================== Soln. 02 ===================
// ================================================
class MedianFinder {
    priority_queue<int> lowerq, upperq;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (lowerq.size() > upperq.size()) {
            if (!upperq.empty() && num > -upperq.top()) {
                upperq.push(-num);
            }
            else {
                lowerq.push(num);
                upperq.push(-lowerq.top());
                lowerq.pop();
            }
        }
        else {
            if (!lowerq.empty() && num < lowerq.top()) {
                lowerq.push(num);
            }
            else {
                upperq.push(-num);
                lowerq.push(-upperq.top());
                upperq.pop();
            }
        }
    }
    
    double findMedian() {
        if (lowerq.size() > upperq.size())
            return lowerq.top();
        return (lowerq.top() - upperq.top()) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
