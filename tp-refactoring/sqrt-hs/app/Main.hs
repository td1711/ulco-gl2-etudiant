import Lib

mynegate :: Maybe Double -> Maybe Double
mynegate Nothing = Nothing
mynegate (Just x) = Just (negate x)

main :: IO ()
main = do
    putStrLn "this is sqrt-hs"
    print $ mynegate $ mysqrt 1764
    print $ mynegate $ mysqrt (-1764)

    