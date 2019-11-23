#ifndef JVM_PILHA_FRAMES_HPP
    #define JVM_PILHA_FRAMES_HPP

    #include <vector>
    #include "../Tipos/Frame.hpp"

    class PilhaFrames{
        private:
            std::vector<Frame> pilha_frames;

        public:
            PilhaFrames() {};

            void push (Frame const &frame);

            Frame pop ();

            void deletar();
    };
#endif
