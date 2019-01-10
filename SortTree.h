#ifndef _SORT_TREE_HPP_
#define _SORT_TREE_HPP_

class SortLeaf {
	public:
		SortLeaf(float fnum):value(fnum),parent(NULL), smallLeaf(NULL), bigLeaf(NULL) {};
		~SortLeaf() {
			if(smallLeaf != NULL) delete smallLeaf;
			if(bigLeaf != NULL) delete bigLeaf;
		};
		float getValue() { return value;};
		SortLeaf* getParent() { return parent;};
		SortLeaf* getSmallLeaf() { return smallLeaf;};
		SortLeaf* getBigLeaf() { return bigLeaf;};
		void setParent(SortLeaf* leaf) { parent = leaf;};
		void setSmallLeaf(SortLeaf* leaf) { smallLeaf = leaf;};
		void setBigLeaf(SortLeaf* leaf) { bigLeaf = leaf;};
		void append(float fnum) {
			if(fnum < value) {
				if(smallLeaf != NULL) {
					smallLeaf->append(fnum);
				}
				else {
					setSmallLeaf(new SortLeaf(fnum));
					smallLeaf->setParent(this);
				}
			}
			else {
				if(bigLeaf != NULL) {
					bigLeaf->append(fnum);
				}
				else {
					setBigLeaf(new SortLeaf(fnum));
					bigLeaf->setParent(this);
				}
			}
		};
	private:
		float value;
		SortLeaf* parent;
		SortLeaf* smallLeaf;
		SortLeaf* bigLeaf;
};


#endif
