#define DEBUGH
#ifndef IOSTREAMH
      #include <iostream>
#endif
#define IOSTREAMH

#ifdef DEBUG
      #define trace1(x)           std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<"\n";
      #define trace2(x,y)         std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<"\n";
      #define trace3(x,y,z)       std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<"\n";
      #define trace4(a,b,c,d)     std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<"\n";
      #define trace5(a,b,c,d,e)   std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<"\n";
      #define trace6(a,b,c,d,e,f) std::cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<"\n";
#else
      #define trace1(x)
      #define trace2(x,y)
      #define trace3(x,y,z)
      #define trace4(a,b,c,d)
      #define trace5(a,b,c,d,e)
      #define trace6(a,b,c,d,e,f)
#endif
