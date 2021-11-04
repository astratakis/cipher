
typedef char* string;

string encrypt_vigeneres(const string __plain_text, const string __key);
string decrypt_vigeneres(const string __encrypted, const string __key);

string encrypt_caesars(const string __plain_text, const int shift);
string decrypt_caesars(const string __encrypted, const int shift);

char *encrypt_otp();