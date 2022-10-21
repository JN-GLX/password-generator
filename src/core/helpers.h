template<class F>
void repeat(unsigned times, F callback) {
    while (times--) callback();
}

