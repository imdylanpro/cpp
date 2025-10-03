/* 
Dylan Nelson
October 03, 2025
Short_Template_Example\\main.cpp
*/

// templates are defined with "template" keyword,
// template parameters can be either "class" or "typename" keyword.
// This is a template class.
template<typename X, typename Y, typename Z>
struct MyTemplateClass {
	X foo(Y& y);
private:
	Z* member;
};

// How to provide implementation of foo.
template<typename X, typename Y, typename Z>
X MyTemplateClass< X, Y, Z >::foo(Y& y) {
	return static_cast<Z>(y + *member);
}

// template functions are also possible.
template<typename U, typename V, typename W>
U my_template_function(V& arg1, const W* arg2) {

}