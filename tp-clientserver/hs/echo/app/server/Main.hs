{-# LANGUAGE OverloadedStrings #-}

import Control.Monad (forever)
import qualified Data.Text as T
import qualified Network.WebSockets as WS

main :: IO ()
main = do
    let port = 9000
    putStrLn $ "running server on port " ++ show port
    WS.runServer "0.0.0.0" port serverApp

serverApp :: WS.PendingConnection -> IO ()
serverApp pc = do
    conn <- WS.acceptRequest pc
    putStrLn "connected"
    WS.withPingThread conn 30 (putStrLn "disconnected") (handleConn conn)

handleConn :: WS.Connection -> IO ()
handleConn conn = do
    WS.sendTextData conn ("connected to echo-server" :: T.Text)
    forever $ do
        msg <- WS.receiveDataMessage conn
        WS.sendTextData conn (WS.fromDataMessage msg :: T.Text)
        putStrLn $ "echoed: " <> show msg

