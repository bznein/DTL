#include <type_traits>
#include <utility>
#include <vector>
#include <iostream>
namespace dtl
{
  /* Functions for convenient printing of various structures */
  namespace details
  {
    template<typename S, typename T>
      class is_streamable
    {
      template<typename SS, typename TT>
        static auto test(SS&& s, TT&& t)
        -> decltype(std::forward<SS>(s) << std::forward<TT>(t));

      struct dummy_t {};
      static dummy_t test(...);

      using return_type = decltype(test(std::declval<S>(), std::declval<T>()));

    public:
      static const bool value = !std::is_same<return_type, dummy_t>::value;
    };
  }

  /* Todo, this is just a stub, should have parameters for stream, delimiters, types etc */
  template <typename T>
    void print(std::vector<T> t, char endchar ='\n', bool indexed = false)
    {
      static_assert(details::is_streamable<std::ostream, T>::value, "Given type is not streamable");
      for (const auto & el : t)
        std::cout << el << endchar;
      std::cout << std::endl;
    }




}
