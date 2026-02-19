template<typename T, typename = void>
struct has_equal_operator : std::false_type {};

template<typename T>
struct has_equal_operator<T, std::void_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type {};
