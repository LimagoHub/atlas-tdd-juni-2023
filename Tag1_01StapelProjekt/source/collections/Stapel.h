//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once

namespace collections {
    class Stapel {



    public:
        static constexpr int size{10};
        Stapel();

        ~Stapel() = default;



        void push(int value);
        int pop();

        bool is_empty()  const;
        bool is_full() const;
    private:
        int data[Stapel::size];
        int index;

    };
}
