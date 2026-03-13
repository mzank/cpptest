#include <mdspan>
#include <iostream>
#include <vector>

int main()
{
  std::vector<double> vec{2.4, 4.6, 6.2, -20.0, -5.4, -6.7};

  std::cout << "vec : ";
  for (auto x : vec)
	  std::cout << x << "  ";
  std::cout << "\n";

  auto md =  std::mdspan(vec.data(),3,2);
  std::cout << "md :\n";
  for (int i = 0; i < md.extent(0); ++i)
  {
	  for (int j=0; j<md.extent(1); ++j)
	  {
		  std::cout << md[i,j] << "  ";
	  }
	  std::cout << "\n";
  }

    
  std::span<double> sp(vec);
  std::cout << "\nspan over vec : ";
  for (auto x : sp)
      std::cout << x << "  ";
  std::cout << "\n";

  auto sub = sp.subspan(2, 3);

  std::cout << "subspan (index 2, length 3) : ";
  for (auto x : sub)
      std::cout << x << "  ";
  std::cout << "\n";
	
  return EXIT_SUCCESS;
}
