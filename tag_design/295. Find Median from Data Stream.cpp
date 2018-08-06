template<typename T,typename U>
class DynamicArray
{
public:
    void Insert(T num)
    {
        if(((min.size()+max.size())&1)==0)
        {
            //even number
            if(max.size()>0&&num<max[0])
            {
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<T>());
                
                num = max[0];
                
                pop_heap(max.begin(),max.end(),less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<T>());
        }else
        {
            if(min.size()>0&&num>min[0])
            {
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<T>());
                
                num = min[0];
                
                pop_heap(min.begin(),min.end(),greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<T>());
        }
    }
    U GetMedian()
    {
        int size = min.size()+max.size();
        if(size==0)
            return 0;
        U median = 0;
        if((size&1)==1)
            median = min[0];
        else
            median = 1.0*(min[0]+max[0])/2;
        return median;
    }
private:
    std::vector<T> min;
    std::vector<T> max;
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        dynamicArray.Insert(num);
    }
    
    double findMedian() {
        return dynamicArray.GetMedian();
    }
private:
    DynamicArray<int,double> dynamicArray;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */