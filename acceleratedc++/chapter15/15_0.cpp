#include<iostream>
#include<string>

class Pic_base{ };

class String_Pic: public Pic_base{ };
class Frame_Pic: public Pic_base{ };
class VCat_Pic: public Pic_base{ };
class Hcat_Pic:public Pic_base{ };

class Picture{
	friend std::ostream& operator << (std::ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);
	public:
		Picture(const std::vector<std::string>& = std::vector<std::string>());
	private:
		Ptr<Pic_base> p;
}

class Pic_base{
	friend std::ostream& operator << (std::ostream&, const Picture&);
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;
	typedef std::vector<std::string> :: size_type ht_sz;
	typedef std::string::size_type wd_sz;

	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;
	public:
	virtual ~Pic_base() { }
	protected:
	static void pad(std::ostream& os, wd_sz beg, wd_sz end){
		while(beg != end){
			os << " ";
			++beg;
		}
	}
}

class Frame_Pic : pulic Pic_base {
	friend Picture frame(const Picture&);
	Ptr<Pic_base> p;
	Frame_Pic(const Ptr<Pic_base>& pic): p(pic) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
}

class VCat_Pic: public Pic_base{
	friend Picture vcat(const Picture&, const Picture&);
	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

class HCat_Pic: public Pic_base{
	friend Picture hcat(const Picture&, const Picture&);
	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& i, const Ptr<Pic_base>& r):left(1), right(r){ }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
 };

class String_Pic: public Pic_base{
	friend class Picture;
	std::vector<std::string> data;
	String_Pic(const std:: vector<std::string>& v: data(v)){ }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator << (std::ostream&, const Picture&);

Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& 1, const Picture& r)
{
	return new HCat_Pic(1.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_Pic(t.p, b.p);
}

ostream& operator << (ostream& os, const Picture& picture)
{
	const Pic_base::ht_sz ht = picture.p->height();
	for (Pic_base::ht_sz i = 0; i != ht; ++i){
		picture.p->display(os, i, false);
		os << endl;
	}

	return os;
}

Pic_base::wd_sz String_Pic :: width() const
{
	Pic_base::wd_sz n = 0;
	for ( Pic_base :: ht_sz i = 0; i != data.size(); ++i)
		n = std::max(n, data[i].size());

	return n;
}

void String_Pic::display(ostream& os, ht_sz row,bool do_pad) const
{
	wd_sz start = 0;

	if (row < height()){
		os << data[row];
		start = data[row].size();
	}

	if (do_pad)
		pad(os, start, width());
}

void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz w = 0;
	if (row < top -> height()){
		top->display(os, row, do_pad);
		w = top->width();
	}else if(row < height()){
		bottom->display(os, row- top->height(), do_pad);
		w = bottom->width();
	}
	if (do_pad)
		pad(os, w, width());
}

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	if (row >= height()){

		if (do_pad)
			pad(os, 0, width());
	}else {
		if (row == 0 || row == height() - 1){
			os << string(width(), '*');
		}else if(row == 1 || row == height() - 2){
			os  << '*';
			pad(os, 1, width() -1);
			os << '*';
		}else{
			os << "* ";
			p->display(os, row - 2, true);
			os << " *";
		}
	}
}
