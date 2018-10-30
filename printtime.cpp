//print time in format "2018-10-30 13:43:31.249071 "
static_assert(sizeof(decltype(now().time_since_epoch()))==sizeof(long long));
void printtime(FILE*f=stdout){
	time_t t=time(0);
	char buf[32];
	strftime(buf,31,"%F %T",std::localtime(&t));
	fputs(buf,f);
	fprintf(f,".%06lld ",chrono::duration_cast<chrono::microseconds>(now().time_since_epoch()%std::chrono::system_clock::duration::period::den));
}
