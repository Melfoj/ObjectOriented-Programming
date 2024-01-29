#ifndef _stek_h_
#define _stek_h_

template<typename T = int, int kap = 2>
class Stek {
	T stek[kap];
	int vrh;
public:
	Stek() { vrh = 0; }

	void stavi(const T& t);
	void uzmi(T& t);

	int vel() const { return vrh; }
	void prazni() { vrh = 0; }

	bool prazan() const { return vrh == 0; }
	bool pun() const { return vrh == kap; }
};

template<typename T, int kap>
void Stek<T, kap>::stavi(const T& t) {
	if (vrh == kap) throw "Stek je pun!";
	stek[vrh++] = t;
}

template<typename T, int kap>
void Stek<T, kap>::uzmi(T& t) {
	if (vrh == 0) throw "Stek je prazan!";
	t = stek[--vrh];
}



#endif // !_stek_h_

