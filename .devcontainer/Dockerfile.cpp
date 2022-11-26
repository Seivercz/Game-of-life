FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get install -y \
                    curl \
                    g++ \
                    gdb \
                    # clang \
                    # clang-tools \
                    cmake \
                    git \
                    zsh
                    
RUN chsh -s $(which zsh)
RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"


