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
	//第3号电视机--TV模式--频道11--音量70\n
	cout << "第" << x << "号电视机--" << mode << "模式--频道" << channel << "--音量" << volume << endl;
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
	cout << "播放电视的电视机数量为" << TV::GetTVCount() << endl;
	cout << "播放DVD的电视机数量为" << TV::GetDVDCount() << endl;
	return 0;
}