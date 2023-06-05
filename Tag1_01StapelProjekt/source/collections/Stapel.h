//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once

namespace collections {
    class Stapel {
        int data[10];
        int index;

    public:
        Stapel();

        ~Stapel() = default;



        void push(int value);
        int pop();

        bool is_empty()  const;
        bool is_full() const;

    };
}
