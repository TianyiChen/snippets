inline void _concat_string(string&){}
template<class T,class...R>
inline void _concat_string(string&s,const T&t,const R&...r){
	if constexpr(is_arithmetic_v<remove_const_t<remove_reference_t<T>>>)s+=to_string(t);
	else s+=t;
	_concat_string(s,r...);
}
template<class T,class...R>
inline string concat_string(const T&t,const R&...r){
	if constexpr(is_arithmetic_v<remove_const_t<remove_reference_t<T>>>){
		auto rt=to_string(t);
		_concat_string(rt,r...);return rt;
	} else{
		string rt{t};
		_concat_string(rt,r...);return rt;
	}
}
