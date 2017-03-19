# ANPI-Proyect2

Install the whole library boost, however only requiered boost::math::tools::polynomial 

	Download
		cd /usr/lib/
		wget -O boost_1_63_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.gz/download
		tar xzvf boost_1_55_0.tar.gz
		cd boost_1_63_0
		./bootstrap.sh --prefix=/usr/local
	Build it:
		./b2
	Install it:
		sudo install b2

C++ Version
	Use c++11. The GNU extensions don't violate the standard 
	If using Eclipse: project->properties->C/C++Build->Settings->GCC C++ Compiler->Miscellaneous-> Other flags, add -std=gnu++11 



