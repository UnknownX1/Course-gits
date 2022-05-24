#include <iostream>
#include <string>
using namespace std;

class TV {
private:
	static int TVcount;
	static int DVDcount;
	int volume;
	string mode;
	int channel;
public:
	friend void remote(TV& tv, int m, int volume_, int channel_);
	void Print(int x);
	TV();
	static int GetTVCount();
	static int GetDVDCount();
};

void remote(TV& tv, int m, int volume_, int channel_) {
	string mode_;
	if (m == 1) {
		mode_ = "TV";
	}
	else {
		mode_ = "DVD";
	}
	if (tv.mode != mode_) {
		if (mode_ == "DVD") {
			tv.mode = mode_;
			TV::TVcount -= 1;
			TV::DVDcount += 1;
		}
		else {
			tv.mode = mode_;
			TV::DVDcount -= 1;
			TV::TVcount += 1;
		}
	}
	if (mode_ == "DVD") {
		tv.channel = 99;
	}
	else {
		tv.channel = channel_;
	}
	tv.volume += volume_;
	if (tv.volume < 0) {
		tv.volume = 0;
	}
	if (tv.volume > 100) {
		tv.volume = 100;
	}
}
void TV::Print(int x) {
	//��3�ŵ��ӻ�--TVģʽ--Ƶ��11--����70\n
	cout << "��" << x << "�ŵ��ӻ�--" << mode << "ģʽ--Ƶ��" << channel << "--����" << volume << endl;
}
TV::TV() {
	channel = ++TVcount;
	mode = "TV";
	volume = 50;
}
int TV::GetTVCount() {
	return TVcount;
}
int TV::GetDVDCount() {
	return DVDcount;
}

int TV::TVcount = 0;
int TV::DVDcount = 0;
int main() {
	int n;
	cin >> n;
	TV* t = new TV[n];

	int T;
	cin >> T;
	while (T--) {
		int i, k, x, v;
		cin >> i >> k >> x >> v;
		remote(t[i], k, v, x);
		t[i].Print(i);
	}
	cout << "���ŵ��ӵĵ��ӻ�����Ϊ" << TV::GetTVCount() << endl;
	cout << "����DVD�ĵ��ӻ�����Ϊ" << TV::GetDVDCount() << endl;
	return 0;
}