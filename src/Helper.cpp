#include "Helper.h"

using std::vector;
using std::min;

Helper::Helper(size_t WordLen,  size_t K) {
    	minLength_ = WordLen; 
    	minPref_ = vector<size_t> (K + 1, NOT_FOUND);
}
size_t& Helper::operator[](size_t index) {
	    return minPref_[index];
}
     
Helper Helper::operator*(const Helper& current) {
	Helper answer = *this;
    answer.minLength_ += current.minLength_;
	for (size_t& sizes : answer.minPref_) {
		if (sizes != NOT_FOUND) {
			sizes += current.minLength_;
    	}
   	}
    for (size_t i = 1; i < minPref_.size(); i++) {
        if (minPref_[i] == i) {
			for (size_t j = 1; i + j < current.minPref_.size() ; j++) {
				if (i != NOT_FOUND && current.minPref_[j] != NOT_FOUND){
					answer.minPref_[i + j] = min(answer.minPref_[i + j], i + current.minPref_[j]);
        	    }
        	}
       	}
   	}
	return answer;
}
   
Helper Helper::operator+(const Helper& current) {
	Helper answer = current;
	for (size_t i = 1; i < answer.minPref_.size(); i++) {
		answer.minPref_[i] = min(minPref_[i], answer.minPref_[i]);
    }
    answer.minLength_ = min(answer.minLength_, minLength_);
    return answer;
}
void Helper::Start() {
	minLength_ = 0;
	size_t k = minPref_.size();
    vector<size_t> cost(k, NOT_FOUND);
    for (size_t i = 0; i < k; ++i) {
    	if (minPref_[i] == i) {
			cost[i] = i;
		}
    }
    vector<vector<size_t>> data(k, vector<size_t>(k, NOT_FOUND));
    for (size_t i = 0; i < k; i++) {
        data[i][0] = 0;
    }
	for (size_t i = 1; i < k; i++) {
		for (size_t j = 1; j < k; j++) {
			if (j >= i && data[i - 1][j - i] != NOT_FOUND && cost[i] != NOT_FOUND) {
				data[i][j] = min(data[i - 1][j], data[i - 1][j - i] + cost[i]);
    	    } else {
    	        data[i][j] = data[i - 1][j];
    	    }
    	}
   	}
    for (size_t i = 0; i < k; i++) {
		minPref_[i] = min(data[k - 1][i], minPref_[i]);
    }
    for (size_t i = 1; i < k; i++) {
		if (minPref_[i] == i) {
			for (size_t j = i; j < minPref_.size(); j += i) {
				minPref_[j] = j;
    	    }
    	}
   	}
   	for (size_t i = 1; i < k; i++) {
		if (minPref_[i] == i) {
			for (size_t j = 1; j < minPref_.size(); ++j) {
				size_t q = (j % i != 0);
				minPref_[j] = min(minPref_[j], i * (j / i + q));
    	    }
    	}
   	}
}


