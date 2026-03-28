#!/bin/bash
set -e

cd "$(dirname "$0")"

export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-

make ARCH="$ARCH" CROSS_COMPILE="$CROSS_COMPILE" chopin_defconfig
perl -0pi -e 's/^CONFIG_BPF_EVENTS=y$/# CONFIG_BPF_EVENTS is not set/m' .config
yes "" | make ARCH="$ARCH" CROSS_COMPILE="$CROSS_COMPILE" oldconfig
perl -0pi -e 's/^CONFIG_BPF_EVENTS=y$/# CONFIG_BPF_EVENTS is not set/m' .config
make -j"$(nproc)" ARCH="$ARCH" CROSS_COMPILE="$CROSS_COMPILE"
