
/**
 ** Definition for an interval.
 ** struct Interval {
 **     int start;
 **     int end;
 **     Interval() : start(0), end(0) {}
 **     Interval(int s, int e) : start(s), end(e) {}
 ** };
 **/
vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.empty()) return vector<Interval>();
    sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;});
    vector<Interval> res;
    res.push_back(intervals[0]);
    for(auto it : intervals){
        if(res.back().end<it.start)
            res.push_back(it);
        else
            res.back().end = max(res.back().end,it.end);
    }
    return res;
}
