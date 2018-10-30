#include<bits/stdc++.h>
#include<string_view>
#include<openssl/hmac.h>
using namespace std;
struct HMAC256{
	HMAC_CTX*ctx;
	const string_view key;
	char result[65];//in hex
	unsigned _sz;
	HMAC256(string_view k):key{k}{
		result[64]=0;
		ctx=HMAC_CTX_new();
		HMAC_Init_ex(ctx,key.data(),key.size(),EVP_sha256(),0);
	}
	~HMAC256(){
		HMAC_CTX_free(ctx);
	}
	const char* compute(string_view msg){
		HMAC_Init_ex(ctx,0,0,0,0);
		HMAC_Update(ctx,(const unsigned char*)msg.data(),msg.size());
		HMAC_Final(ctx,(unsigned char*)result,&_sz);
		for(int i=_sz-1;i>=0;--i){
			result[i<<1|1]="0123456789abcdef"[result[i]&0xf];
			result[i<<1]="0123456789abcdef"[(unsigned char)result[i]>>4];
		}
		return result;
	}
};
int main(){
	HMAC256 h("aa");
	h.compute("bb");
	cout<<h.result<<endl;
	h.compute("cc");
	cout<<h.result<<endl;
	/*
	f785efdd574f1c0fa884aca390cd696f45b965502e315726200008d80a8d4424
	bb02c03ceb8da8ffb0095a7dcb766c31951065548787475135fc781e356af870
	*/
}
