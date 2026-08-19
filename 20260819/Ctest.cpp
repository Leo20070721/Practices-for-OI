#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

const int MAXN=1e5+12;
int N,ques[MAXN],ans1[MAXN],ans2[MAXN];
std::string sget;
bool check(){
	freopen("Ctest.in","r",stdin);
	std::cin>>N>>N;
	for(int i=1;i<=N;i++) std::cin>>ques[i];
	freopen("C.out","r",stdin);
	std::cin>>sget;
	for(int i=1;i<=N;i++){
		std::cin>>ans1[i];
		if(ans1[i]==i) return false;
	}
	for(int i=1;i<=N;i++){
		std::cin>>ans2[i];
		if(ans2[i]==i) return false;
	}
	for(int i=1;i<=N;i++){
		if(ques[ans1[ans2[i]]]!=i) return false;
	}
	fclose(stdin);
	return true;
}

void display(){
	freopen("Ctest.in","r",stdin);
	std::cin>>N>>N;
	std::cout<<"1\n"<<N<<"\n";
	for(int i=1;i<=N;i++){
		std::cin>>ques[i];
		std::cout<<ques[i]<<" ";
	}std::cout<<"\n\n";
	
	freopen("C.out","r",stdin);
	std::cin>>sget;
	std::cout<<sget<<"\n";
	for(int i=1;i<=N;i++){
		std::cin>>ans1[i];
		std::cout<<ans1[i]<<" ";
	}std::cout<<"\n";
	for(int i=1;i<=N;i++){
		std::cin>>ans2[i];
		std::cout<<ans2[i]<<" ";
	}std::cout<<"\n";
}

int main() {
  // For Windows
  // 对拍时不开文件输入输出
  // 当然，这段程序也可以改写成批处理的形式
  while (true) {
    system("Cgen > Ctest.in");  // 数据生成器将生成数据写入输入文件
    system("C2.exe < Ctest.in > C.out");  // 获取程序1输出
//    system("C.exe < Ctest.in > b.out");  // 获取程序2输出
    if (!check()) {
      // 该行语句比对输入输出
      // fc返回0时表示输出一致，否则表示有不同处
      display();
      system("pause");  // 方便查看不同处
      return 0;
      // 该输入数据已经存放在test.in文件中，可以直接利用进行调试
    }else{
    	std::cout<<N<<" Passed\n";
	}
  }
}
