#include <iostream>
#include <task6_20.h>

int main () {
    task6_20 unit("data.txt");
    std::cout << unit << std::endl;

    std::vector <student> result = unit.findByDate("12.05.2006");
    for (student u: result) {
        std::cout << u.first_name << " " << u.result.mark << std::endl;
    }

    student st;
    st.number = "66666";
    st.birth_day = "11.09.2002";
    st.first_name = "Andrianov";
    st.group = "BBBO-07-23";
    st.result.subject = "programming";
    st.result.date = "32.13.2025";
    st.result.mark = 1;
    unit.append(st);

    std::cout << unit << std::endl;

    unit.removeNodeFromIndex(3);
    std::cout << unit << std::endl;
    std::cout << unit.countStudentsBySubject("mathematics") << std::endl;

    unit.toFile("result.txt");

    return 0;
}