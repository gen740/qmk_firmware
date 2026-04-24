{
  description = "Flake shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
  };

  outputs =
    inputs@{ flake-parts, nixpkgs, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      systems = nixpkgs.lib.platforms.all;

      perSystem =
        { pkgs, ... }:
        {
          devShells.default = pkgs.mkShell {
            packages = [
              pkgs.qmk
              pkgs.python313Packages.toml
            ];
          };

          packages.default = pkgs.stdenv.mkDerivation {
            name = "hello";
            src = ./.;
            buildInputs = [ ];
            installPhase = ''
              mkdir -p $out/bin
              echo "Hello, world!" > $out/bin/hello
              chmod +x $out/bin/hello
            '';
          };
        };
    };
}
