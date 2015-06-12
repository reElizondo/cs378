// --------
// StrCmp.h
// --------

#ifndef StrCmp_h
#define StrCmp_h

int my_strcmp (const char* a, const char* b) {
    while (*a != 0) {
        if ((*b == 0) || (*a != *b))
            break;
        ++a;
        ++b;}
    return *a - *b;}

#endif // StrCmp_h
