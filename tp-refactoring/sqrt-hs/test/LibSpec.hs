module LibSpec (main, spec) where

import Test.Hspec

import Lib

main :: IO ()
main = hspec spec

spec :: Spec
spec = 
    describe "mysqrt" $ do
        it "0" $ mysqrt 0 `shouldBe` Just 0
        it "1764" $ mysqrt 1764 `shouldBe` Just 42
        it "(-1764)" $ mysqrt (-1764) `shouldBe` Nothing
