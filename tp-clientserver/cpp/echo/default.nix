{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
  name = "echo";

  src = ./. ;

  buildInputs = with pkgs; [
    cmake
    libhv
  ];

  shellHook = ''
    echo ${pkgs.libhv}
  '';

}

