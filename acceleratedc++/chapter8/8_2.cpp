#include<iterator>
#include<string>
#include<algorithm>


using std::swap;


template <class In1, class In2>
bool equal(In1 first1, In2 last1, In1 first2)
{
    while(first1 != last1){
        if (!(first1 == first2)){
            return false;
        }
        first1++;
        first2++;
    }
    return true;
}

template<class In>
In search(In first1, In last1,In first2,In last2)
{
    if (first2 == last2){
        return first1;
    }
    
    while (first1 != last1){
        In iter1 = first1;
        In iter2 = first2;
        while(*iter1 == *iter2){
            iter1++;
            iter2++;
            if(iter2 == last2) return first1;
            if(iter1 == last1) return last1;
        }
        ++first1;
    }
}

template <class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val)
{
    while (first!=last) {
        if (*first==val) return first;
        ++first;
    }
    return last;
}

template<class InputIterator, class Predicateiterator>
InputIterator find_if(InputIterator first1, InputIterator last1, Predicateiterator Pred)
{
    while(first1 != last1){
        if (Pred(*first1)){
            return first1;
        }
        first1++;
    }

    return false;
}

template <class In, class Out>
Out copy(In first1, In last1, Out dest)
{
    while(first1 != last1)
    {
        *dest = *first1;
        dest++;
    }
     
    return dest;
}

template<class In,class Out, class T>
Out remove_copy(In first1, In last1, Out first2, T val)
{
    while(first1 != last1)
    {
        if(*first1 != val)
        {
           *first2 = *first1;
           first2++;
        }
        first1++;
    }
   
    return first2;
}

template <class In, class Out, class Pred>
Out remove_copy_if(In first1, In last1, Out first2, Pred p)
{
    while(first1 != last1)
    {
        if (p(*first1))
        {
            *first2 = first1;
            first2;
        }
        first1++;
    }

    return first2;
}

template <class In, class Out, class Trans>
Out transform(In first1, In last1, In first2, Out dest, Trans t)
{
    while (first1 != last1)
    {
        *dest = t(first1, first2);
        first1++;
        first2++;
        dest++;
    }

    return dest;
}

template<class In,class Out,class Par>
Out partition(In first1,In last1, Par p)
{
    while(first1 != last1)
    {
        while (p(*first1))
        {
            first1++;
            if(first1 == last1) return first1;
        }
        do{
            last1--;
            if (last1 == first1) return first1;
        }while(!p(*last1));
        swap(*first1,*last1);
        first1++;
    }
}

template<class In, class T>
T accumulate(In first, In last, T result)
{
    while(first != last)
    {
        result += *first;       
        first++;
    }

    return result;
}

int main()
{
    return 0;
}
