template<typename Tp>
void read(Tp &s){
	s=0;
	char c=getchar();
	while(c>57||c<48) c=getchar();
	while(47<c&&c<58)
	{
		s=s*10;
		s=s+c-48;
		c=getchar();
	}
}
