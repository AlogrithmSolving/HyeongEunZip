#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;
long long p, q, n, pi_n, e = 17, d=0;
long long enc_res, dec_res, message;
long long random_number_generation(){
	long long index = 0;
	index = 16384 + (rand() % 16384);
	return index;
}
long long moduler(long long k, long long mod){
	k %= mod;
	if (k < 0){
		k += mod;
	}
	return k;
}
long long square_and_multiply(long long a, long long p, long long mod){

	stack<long long> stk;
	long long result = 1;
	while (p>0)
	{
		long long tmp;
		tmp = p & 1;
		stk.push(tmp);
		p = p >> 1;
	}
	while (stk.empty() == false)
	{
		result = result * result;
		result = moduler(result, mod); // 제곱

		if (stk.top() == 1){ // 1일 경우 곱하기 a
			result = result * a;
			result = moduler(result, mod);
		}
		else if (stk.top() == 0){
			
		}
		else{
			cout << "errrrrrrrroooooooor" << endl;
		}
		stk.pop();
	}

	return result;
}
bool miller_rabin(long long p){
	long long is_prime = p;
	for (size_t i = 2; i < 12; i++)
	{
		is_prime = square_and_multiply(i, p-1, p);
		if (is_prime != 1){
			return false;
		}
	}
	
	return true;
}
long long extended_euclid(long long m,long long b){
	long long a1 = 1, a2 = 0, a3 = m;
	long long b1 = 0, b2 = 1, b3 = b;

	long long t1, t2, t3;
	long long q;

	while (true){
		if (b3 == 0)
			return 0;
		if (b3 == 1)
			return (moduler(b2, m));
		q = a3 / b3;
		t1 = a1 - q*b1;
		t1 = moduler(t1, m);
		
		t2 = a2 - q*b2;
		t2 = moduler(t2, m);
		
		t3 = a3 - q * b3;
		t3 = moduler(t3, m);
		
		a1 = b1;
		a2 = b2;
		a3 = b3;
		
		b1 = t1;
		b2 = t2;
		b3 = t3;
	}
	return 0;
}
long long gcd(long long a, long long b){
	long long c;
	while (b != 0){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}
void set_key(){
	bool is_prime1 = false, is_prime2 = false;
	while (is_prime1 != true){
		p = random_number_generation();
		is_prime1 = miller_rabin(p);
	}
	while (is_prime2 != true || p == q){
		q = random_number_generation();
		is_prime2 = miller_rabin(q);
	}
	n = p * q;
	pi_n = (p - 1) * (q - 1);

	d = extended_euclid(pi_n,e);
}
void encryption(){
	cout << "message를 입력하세요.(n보다 작은 수로 입력할 것)" << endl;
	cin >> message;

	enc_res = square_and_multiply(message, e, n);
}
void decryption()
{
	dec_res = square_and_multiply(enc_res, d, n);
}
int main(){
	srand(time(NULL));
	while (d == 0){
		set_key();
	}
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "pi_n = " << pi_n << endl;
	cout << "d = " << d << endl;
	cout << "n = " << n << endl;

	encryption();
	cout << "encryption result : " << enc_res << endl;
	decryption();
	cout << "decryption result : " << dec_res << endl;

	if (message == dec_res){
		cout << "결과 값이 같습니다." << endl;
	}

	return 0;
}