#pragma once

template<typename Key, typename Comparator>
struct SkipList<Key, Comparator>::Node {
	explicit Node(const Key& k) :key(k) {}

	Key const key;	

	Node* Next(int n) {

	}
};


template<typename Key, typename Comparator>
class SkipList
{
public:
	SkipList(Comparator cmp);

	SkipList(const SkipList&) = delete;

	SkipList& operator=(const SkipList&) = delete;

	void Insert(const Key& key);

	bool Contains(const Key& key)const;

private:
	enum { kMaxHeight = 12};


	Node *head_;

	Comparator const compare_;

	std::atomic<int> max_height_;
	
	Random rnd_;
};

